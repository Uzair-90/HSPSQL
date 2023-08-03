import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleRatingsDisplay() {
  const [titleRatingsData, setTitleRatingsData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitleRatingsData = async () => {
      try {
        const response = await axios.get(`http://localhost:3001/api/title_ratings?offset=${(currentPage - 1) * 10}&limit=10`);
        setTitleRatingsData(response.data);
      } catch (error) {
        console.error('Error fetching title_ratings data:', error);
      }
    };

    fetchTitleRatingsData();
  }, [currentPage]);

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Ratings</h2>
      <table>
        <thead>
          <tr>
            <th>Title ID</th>
            <th>Average Rating</th>
            <th>Number of Votes</th>
          </tr>
        </thead>
        <tbody>
          {titleRatingsData.map((item) => (
            <tr key={item.tconst}>
              <td>{item.tconst}</td>
              <td>{item.average_rating}</td>
              <td>{item.num_votes}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitleRatingsDisplay;
