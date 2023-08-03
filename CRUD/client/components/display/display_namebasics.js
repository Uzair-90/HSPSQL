import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function NameBasicsDisplay() {
  const [nameBasicsData, setNameBasicsData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);


  useEffect(() => {
    const fetchNameBasicsData = async () => {
      try {
        const response = await axios.get(`http://localhost:3001/api/name_basics?offset=${(currentPage - 1) * 10}&limit=10`);
        setNameBasicsData(response.data);
      } catch (error) {
        console.error('Error fetching name_basics data:', error);
      }
    };
  
    fetchNameBasicsData();
  }, [currentPage]);
  

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Name Basics</h2>
      <table>
        <thead>
          <tr>
            <th>Birth Year</th>
            <th>Death Year</th>
            <th>Nconst</th>
            <th>Primary Name</th>
            <th>Primary Profession</th>
            <th>Known For Titles</th>
          </tr>
        </thead>
        <tbody>
          {nameBasicsData.map((item) => (
            <tr key={item.nconst}>
              <td>{item.birth_year}</td>
              <td>{item.death_year}</td>
              <td>{item.nconst}</td>
              <td>{item.primary_name}</td>
              <td>
                {Array.isArray(item.primary_profession) ? item.primary_profession.join(', ') : 'N/A'}
              </td>
              <td>
                {Array.isArray(item.known_for_titles) ? item.known_for_titles.join(', ') : 'N/A'}
              </td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default NameBasicsDisplay;
