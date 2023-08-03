import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleCrew() {
  const [formData, setFormData] = useState({
    tconst: '',
    directors: '',
    writers: '',
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      // Convert directors and writers to arrays
      let parsedDirectors = formData.directors.split(',').map((item) => item.trim());
      let parsedWriters = formData.writers.split(',').map((item) => item.trim());

      // Send the updated formData to the server
      await axios.post('http://localhost:3001/api/title_crew', {
        tconst: formData.tconst,
        directors: parsedDirectors,
        writers: parsedWriters,
      });

      // Clear the form after successful submission
      clearForm();
    } catch (error) {
      console.error('Error creating title_crew:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      tconst: '',
      directors: '',
      writers: '',
    });
  };

  return (
    <div className="titleCrew-container">
      <h2>Title Crew</h2>
      <form onSubmit={handleSubmit}>
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
          <label>Directors (comma-separated):</label>
          <input
            type="text"
            name="directors"
            value={formData.directors}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Writers (comma-separated):</label>
          <input
            type="text"
            name="writers"
            value={formData.writers}
            onChange={handleChange}
          />
        </div>
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitleCrew;
