import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleAkasDisplay() {
  const [titleAkasData, setTitleAkasData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitleAkasData = async () => {
      try {
        const response = await axios.get(`http://localhost:3001/api/title_akas?offset=${(currentPage - 1) * 10}&limit=10`);
        setTitleAkasData(response.data);
      } catch (error) {
        console.error('Error fetching title_akas data:', error);
      }
    };
  
    fetchTitleAkasData();
  }, [currentPage]);
  

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Akas</h2>
      <table>
        <thead>
          <tr>
            <th>Title ID</th>
            <th>Ordering</th>
            <th>Title</th>
            <th>Region</th>
            <th>Language</th>
            <th>Types</th>
          </tr>
        </thead>
        <tbody>
          {titleAkasData.map((item) => (
            <tr key={item.title_id}>
              <td>{item.title_id}</td>
              <td>{item.ordering}</td>
              <td>{item.title}</td>
              <td>{item.region}</td>
              <td>{item.language}</td>
              <td>
                {Array.isArray(item.types) ? item.types.join(', ') : 'N/A'}
              </td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitleAkasDisplay;
