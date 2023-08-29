import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function UpdateTitleAkas() {
  const [titleId, setTitleId] = useState('');
  const [selectedEntity, setSelectedEntity] = useState('');
  const [entityValue, setEntityValue] = useState('');

  const handleUpdate = async () => {
    try {
      const data = { [selectedEntity]: entityValue };
      const response = await axios.put(`http://localhost:3001/api/title_akas/${titleId}`, data);

      // Handle success, show a success message or perform any other actions needed
      console.log('Update successful:', response.data);

      // Clear the form after a successful update
      setTitleId('');
      setSelectedEntity('');
      setEntityValue('');
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      console.error('Error updating title_akas data:', error);
    }
  };

  return (
    <form>
      <h2>Update Title Akas</h2>
      <div>
        <label htmlFor="titleId">Title ID:</label>
        <input type="text" id="titleId" value={titleId} onChange={(e) => setTitleId(e.target.value)} />
      </div>
      <div>
        <label htmlFor="selectEntity">Select Entity to Update:</label>
        <select id="selectEntity" value={selectedEntity} onChange={(e) => setSelectedEntity(e.target.value)}>
          <option value="">Select an entity</option>
          <option value="ordering">Ordering</option>
          <option value="is_original_title">Is Original Title</option>
          <option value="region">Region</option>
          <option value="types">Types</option>
          <option value="attributes">Attributes</option>
          <option value="language">Language</option>
          <option value="title">Title</option>
        </select>
      </div>
      <div>
        <label htmlFor="entityValue">Entity Value:</label>
        <input type="text" id="entityValue" value={entityValue} onChange={(e) => setEntityValue(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleUpdate}>Update Title Akas</button>
    </form>
  );
}

export default UpdateTitleAkas;
