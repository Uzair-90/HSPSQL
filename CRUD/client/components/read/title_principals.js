import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitlePrincipals() {
  const [formData, setFormData] = useState({
    ordering: '',
    tconst: '',
    nconst: '',
    category: '',
    job: '',
    characters: ''
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      await axios.post('http://localhost:3001/api/title_principals', formData);
      clearForm();
    } catch (error) {
      console.error('Error creating title_principals:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      ordering: '',
      tconst: '',
      nconst: '',
      category: '',
      job: '',
      characters: ''
    });
  };

  return (
    <div>
      <h2>Title Principals</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Ordering:</label>
          <input
            type="number"
            name="ordering"
            value={formData.ordering}
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
          <label>Nconst:</label>
          <input
            type="text"
            name="nconst"
            value={formData.nconst}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Category:</label>
          <input
            type="text"
            name="category"
            value={formData.category}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Job:</label>
          <input
            type="text"
            name="job"
            value={formData.job}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Characters:</label>
          <input
            type="text"
            name="characters"
            value={formData.characters}
            onChange={handleChange}
          />
        </div>
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitlePrincipals;
