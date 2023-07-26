import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleBasics() {
  const [formData, setFormData] = useState({
    startYear: '',
    endYear: '',
    runtimeMinutes: '',
    isAdult: false,
    tconst: '',
    genres: '',
    titleType: '',
    primaryTitle: '',
    originalTitle: '',
  });

  const handleChange = (event) => {
    const { name, value, type } = event.target;

    if (type === 'checkbox') {
      setFormData({ ...formData, [name]: event.target.checked });
    } else {
      setFormData({ ...formData, [name]: value });
    }
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      // Convert genres to an array
      let parsedGenres = formData.genres.split(',').map((item) => item.trim());

      // Send the updated formData to the server
      await axios.post('http://localhost:3001/api/title_basics', {
        startYear: formData.startYear,
        endYear: formData.endYear,
        runtimeMinutes: formData.runtimeMinutes,
        isAdult: formData.isAdult,
        tconst: formData.tconst,
        genres: parsedGenres,
        titleType: formData.titleType,
        primaryTitle: formData.primaryTitle,
        originalTitle: formData.originalTitle,
      });

      // Clear the form after successful submission
      clearForm();
    } catch (error) {
      console.error('Error creating title_basics:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      startYear: '',
      endYear: '',
      runtimeMinutes: '',
      isAdult: false,
      tconst: '',
      genres: '',
      titleType: '',
      primaryTitle: '',
      originalTitle: '',
    });
  };

  return (
    <div className="titleBasics-container">
      <h2>Title Basics</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Start Year:</label>
          <input
            type="number"
            name="startYear"
            value={formData.startYear}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>End Year:</label>
          <input
            type="number"
            name="endYear"
            value={formData.endYear}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Runtime Minutes:</label>
          <input
            type="number"
            name="runtimeMinutes"
            value={formData.runtimeMinutes}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Is Adult:</label>
          <input
            type="checkbox"
            name="isAdult"
            checked={formData.isAdult}
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
          <label>Genres (comma-separated):</label>
          <input
            type="text"
            name="genres"
            value={formData.genres}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Title Type:</label>
          <input
            type="text"
            name="titleType"
            value={formData.titleType}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Primary Title:</label>
          <input
            type="text"
            name="primaryTitle"
            value={formData.primaryTitle}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Original Title:</label>
          <input
            type="text"
            name="originalTitle"
            value={formData.originalTitle}
            onChange={handleChange}
          />
        </div>
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitleBasics;
