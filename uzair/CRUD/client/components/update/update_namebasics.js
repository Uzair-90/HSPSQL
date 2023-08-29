import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';


function UpdateNameBasics() {
  const [nconst, setNconst] = useState('');
  const [selectedEntity, setSelectedEntity] = useState('');
  const [entityValue, setEntityValue] = useState('');

  const handleUpdate = async () => {
    try {
      const data = { [selectedEntity]: entityValue };
      const response = await axios.put(`http://localhost:3001/api/name_basics/${nconst}`, data);

      // Handle success, show a success message or perform any other actions needed
      console.log('Update successful:', response.data);

      // Clear the form after a successful update
      setNconst('');
      setSelectedEntity('');
      setEntityValue('');
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      console.error('Error updating name_basics data:', error);
    }
  };

  return (
    <form>
      <h2>Update Name Basics</h2>
      <div>
        <label htmlFor="nconst">Nconst:</label>
        <input type="text" id="nconst" value={nconst} onChange={(e) => setNconst(e.target.value)} />
      </div>
      <div>
        <label htmlFor="selectEntity">Select Entity to Update:</label>
        <select id="selectEntity" value={selectedEntity} onChange={(e) => setSelectedEntity(e.target.value)}>
          <option value="">Select an entity</option>
          <option value="birth_year">Birth Year</option>
          <option value="death_year">Death Year</option>
          <option value="primary_name">Primary Name</option>
          <option value="primary_profession">Primary Profession</option>
          <option value="known_for_titles">Known for Titles</option>
        </select>
      </div>
      <div>
        <label htmlFor="entityValue">Entity Value:</label>
        <input type="text" id="entityValue" value={entityValue} onChange={(e) => setEntityValue(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleUpdate}>Update Name Basics</button>
    </form>
  );
}

export default UpdateNameBasics;
