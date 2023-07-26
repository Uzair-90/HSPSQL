import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleEpisodes() {
  const [formData, setFormData] = useState({
    seasonNumber: '',
    episodeNumber: '',
    tconst: '',
    parentTconst: '',
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      await axios.post('http://localhost:3001/api/title_episodes', formData);
      clearForm();
    } catch (error) {
      console.error('Error creating title_episodes:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      seasonNumber: '',
      episodeNumber: '',
      tconst: '',
      parentTconst: '',
    });
  };

  return (
    <div className="titleEpisodes-container">
      <h2>Title Episodes</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Season Number:</label>
          <input
            type="number"
            name="seasonNumber"
            value={formData.seasonNumber}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Episode Number:</label>
          <input
            type="number"
            name="episodeNumber"
            value={formData.episodeNumber}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Tconst:</label>
          <input
            type="text"
            name="tconst"
            value={formData.tconst}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Parent Tconst:</label>
          <input
            type="text"
            name="parentTconst"
            value={formData.parentTconst}
            onChange={handleChange}
          />
        </div>
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitleEpisodes;
