import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleBasicsDisplay() {
  const [titleBasicsData, setTitleBasicsData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitleBasicsData = async () => {
      try {
        const response = await axios.get(
          `http://localhost:3001/api/title_basics?offset=${(currentPage - 1) * 10}&limit=10`
        );
        setTitleBasicsData(response.data);
      } catch (error) {
        console.error('Error fetching title_basics data:', error);
      }
    };

    fetchTitleBasicsData();
  }, [currentPage]);

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Basics</h2>
      <table>
        <thead>
          <tr>
            <th>Title ID</th>
            <th>Start Year</th>
            <th>End Year</th>
            <th>Runtime Minutes</th>
            <th>Is Adult</th>
            <th>Genres</th>
            <th>Title Type</th>
            <th>Primary Title</th>
            <th>Original Title</th>
          </tr>
        </thead>
        <tbody>
          {titleBasicsData.map((item) => (
            <tr key={item.tconst}>
              <td>{item.tconst}</td>
              <td>{item.startyear}</td>
              <td>{item.endyear}</td>
              <td>{item.runtimeminutes}</td>
              <td>{item.isadult ? 'Yes' : 'No'}</td>
              <td>{item.genres.join(', ')}</td>
              <td>{item.titletype}</td>
              <td>{item.primarytitle}</td>
              <td>{item.originaltitle}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitleBasicsDisplay;
