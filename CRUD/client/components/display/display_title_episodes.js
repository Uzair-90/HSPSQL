import React, { useState, useEffect } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleEpisodesDisplay() {
  const [titleEpisodesData, setTitleEpisodesData] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    const fetchTitleEpisodesData = async () => {
      try {
        const response = await axios.get(
          `http://localhost:3001/api/title_episodes?offset=${(currentPage - 1) * 10}&limit=10`
        );
        setTitleEpisodesData(response.data);
      } catch (error) {
        console.error('Error fetching title_episodes data:', error);
      }
    };

    fetchTitleEpisodesData();
  }, [currentPage]);

  const handleNextPage = () => {
    setCurrentPage((prevPage) => prevPage + 1);
  };

  return (
    <div>
      <h2>Title Episodes</h2>
      <table>
        <thead>
          <tr>
            <th>Season Number</th>
            <th>Episode Number</th>
            <th>Title ID</th>
            <th>Parent Title ID</th>
          </tr>
        </thead>
        <tbody>
          {titleEpisodesData.map((item) => (
            <tr key={item.tconst + item.season_number + item.episode_number}>
              <td>{item.season_number}</td>
              <td>{item.episode_number}</td>
              <td>{item.tconst}</td>
              <td>{item.parent_tconst}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <button className='glow-on-hover' onClick={handleNextPage}>Load More</button>
    </div>
  );
}

export default TitleEpisodesDisplay;
