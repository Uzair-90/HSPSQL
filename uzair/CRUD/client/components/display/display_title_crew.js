import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleCrewDisplay() {
  const [titleCrewData, setTitleCrewData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitleCrewData = async () => {
      try {
        const response = await axios.get(
          `http://localhost:3001/api/title_crew?offset=${(currentPage - 1) * 10}&limit=10`
        );
        setTitleCrewData(response.data);
      } catch (error) {
        console.error('Error fetching title_crew data:', error);
      }
    };

    fetchTitleCrewData();
  }, [currentPage]);

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Crew</h2>
      <table>
        <thead>
          <tr>
            <th>Title ID</th>
            <th>Directors</th>
            <th>Writers</th>
          </tr>
        </thead>
        <tbody>
          {titleCrewData.map((item) => (
            <tr key={item.tconst}>
              <td>{item.tconst}</td>
              <td>{Array.isArray(item.directors) ? item.directors.join(', ') : 'N/A'}</td>
              <td>{Array.isArray(item.writers) ? item.writers.join(', ') : 'N/A'}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitleCrewDisplay;
