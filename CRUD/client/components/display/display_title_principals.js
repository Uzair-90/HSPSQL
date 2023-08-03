import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitlePrincipalsDisplay() {
  const [titlePrincipalsData, setTitlePrincipalsData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitlePrincipalsData = async () => {
      try {
        const response = await axios.get(
          `http://localhost:3001/api/title_principals?offset=${(currentPage - 1) * 10}&limit=10`
        );
        setTitlePrincipalsData(response.data);
      } catch (error) {
        console.error('Error fetching title_principals data:', error);
      }
    };

    fetchTitlePrincipalsData();
  }, [currentPage]);

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Principals</h2>
      <table>
        <thead>
          <tr>
            <th>Title ID</th>
            <th>Name ID</th>
            <th>Category</th>
            <th>Job</th>
            <th>Characters</th>
            <th>Ordering</th>
          </tr>
        </thead>
        <tbody>
          {titlePrincipalsData.map((item) => (
            <tr key={item.tconst + item.nconst + item.category + item.job}>
              <td>{item.tconst}</td>
              <td>{item.nconst}</td>
              <td>{item.category}</td>
              <td>{item.job}</td>
              <td>{item.characters}</td>
              <td>{item.ordering}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitlePrincipalsDisplay;
