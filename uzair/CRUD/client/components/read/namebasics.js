import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function NameBasics() {
  const [formData, setFormData] = useState({
    birthYear: '',
    deathYear: '',
    nconst: '',
    primaryName: '',
    primaryProfession: '',
    knownForTitles: ''
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      // Convert primaryProfession and knownForTitles to arrays
      let parsedPrimaryProfession = [];
      let parsedKnownForTitles = [];

      if (typeof formData.primaryProfession === 'string') {
        parsedPrimaryProfession = formData.primaryProfession.split(',').map((item) => item.trim());
      }

      if (typeof formData.knownForTitles === 'string') {
        parsedKnownForTitles = formData.knownForTitles.split(',').map((item) => item.trim());
      }

      // Update the formData with the parsed arrays
      setFormData({
        ...formData,
        primaryProfession: parsedPrimaryProfession,
        knownForTitles: parsedKnownForTitles,
      });

      // Send the updated formData to the server
      await axios.post('http://localhost:3001/api/name_basics', {
        birthYear: formData.birthYear,
        deathYear: formData.deathYear,
        nconst: formData.nconst,
        primaryName: formData.primaryName,
        primaryProfession: parsedPrimaryProfession,
        knownForTitles: parsedKnownForTitles,
      });

      // Clear the form after successful submission
      clearForm();
    } catch (error) {
      console.error('Error creating name_basics:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      birthYear: '',
      deathYear: '',
      nconst: '',
      primaryName: '',
      primaryProfession: '',
      knownForTitles: ''
    });
  };

  return (
    <div>
      <h2>Name Basics</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Birth Year:</label>
          <input
            type="number"
            name="birthYear"
            value={formData.birthYear}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Death Year:</label>
          <input
            type="number"
            name="deathYear"
            value={formData.deathYear}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Nconst:</label>
          <input
            type="text"
            name="nconst"
            value={formData.nconst}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Primary Name:</label>
          <input
            type="text"
            name="primaryName"
            value={formData.primaryName}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Primary Profession:</label>
          <input
            type="text"
            name="primaryProfession"
            value={formData.primaryProfession}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Known For Titles:</label>
          <input
            type="text"
            name="knownForTitles"
            value={formData.knownForTitles}
            onChange={handleChange}
          />
        </div>
        <button  type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default NameBasics;
