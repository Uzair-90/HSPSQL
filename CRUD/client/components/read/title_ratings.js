import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleRatings() {
  const [formData, setFormData] = useState({
    averageRating: '',
    numVotes: '',
    tconst: '',
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      await axios.post('http://localhost:3001/api/title_ratings', formData);
      clearForm();
    } catch (error) {
      console.error('Error creating title_ratings:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      averageRating: '',
      numVotes: '',
      tconst: '',
    });
  };

  return (
    <div className="titleRatings-container">
      <h2>Title Ratings</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Average Rating:</label>
          <input
            type="number"
            name="averageRating"
            value={formData.averageRating}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Number of Votes:</label>
          <input
            type="number"
            name="numVotes"
            value={formData.numVotes}
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
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitleRatings;
