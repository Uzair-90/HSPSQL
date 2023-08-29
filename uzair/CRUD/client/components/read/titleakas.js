import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function TitleAkas() {
  const [formData, setFormData] = useState({
    ordering: '',
    isOriginalTitle: '',
    region: '',
    titleId: '',
    types: '',
    attributes: '',
    language: '',
    title: ''
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      // Convert ordering and isOriginalTitle to numbers and boolean respectively
      const parsedOrdering = parseInt(formData.ordering);
      const parsedIsOriginalTitle = formData.isOriginalTitle === 'true';

      // Convert types and attributes to arrays
      const parsedTypes = formData.types.split(',').map((item) => item.trim());
      const parsedAttributes = formData.attributes.split(',').map((item) => item.trim());

      // Send the formData to the server
      await axios.post('http://localhost:3001/api/title_akas', {
        ordering: parsedOrdering,
        isOriginalTitle: parsedIsOriginalTitle,
        region: formData.region,
        titleId: formData.titleId,
        types: parsedTypes,
        attributes: parsedAttributes,
        language: formData.language,
        title: formData.title
      });

      clearForm();
    } catch (error) {
      console.error('Error creating title_akas:', error);
    }
  };

  const clearForm = () => {
    setFormData({
      ordering: '',
      isOriginalTitle: '',
      region: '',
      titleId: '',
      types: '',
      attributes: '',
      language: '',
      title: ''
    });
  };

  return (
    <div>
      <h2>Title Akas Form</h2>
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
          <label>Is Original Title:</label>
          <select name="isOriginalTitle" value={formData.isOriginalTitle} onChange={handleChange}>
            <option value="true">True</option>
            <option value="false">False</option>
          </select>
        </div>
        <div>
          <label>Region:</label>
          <input
            type="text"
            name="region"
            value={formData.region}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Title ID:</label>
          <input
            type="text"
            name="titleId"
            value={formData.titleId}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Types:</label>
          <input
            type="text"
            name="types"
            value={formData.types}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Attributes:</label>
          <input
            type="text"
            name="attributes"
            value={formData.attributes}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Language:</label>
          <input
            type="text"
            name="language"
            value={formData.language}
            onChange={handleChange}
          />
        </div>
        <div>
          <label>Title:</label>
          <input
            type="text"
            name="title"
            value={formData.title}
            onChange={handleChange}
          />
        </div>
        <button type="submit">Add Data</button>
      </form>
    </div>
  );
}

export default TitleAkas;
