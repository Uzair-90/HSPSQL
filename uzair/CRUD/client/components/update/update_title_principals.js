import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function UpdateTitlePrincipals() {
  const [nconst, setNconst] = useState('');
  const [selectedEntity, setSelectedEntity] = useState('');
  const [entityValue, setEntityValue] = useState('');

  const handleUpdate = async () => {
    try {
      const data = { [selectedEntity]: entityValue };
      const response = await axios.put(`http://localhost:3001/api/title_principals/${nconst}`, data);

      // Handle success, show a success message or perform any other actions needed
      console.log('Update successful:', response.data);

      // Clear the form after successful update
      setNconst('');
      setSelectedEntity('');
      setEntityValue('');
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      console.error('Error updating title_principals data:', error);
    }
  };

  return (
    <form>
      <h2>Update Title Principals</h2>
      <div>
        <label htmlFor="nconst">Nconst:</label>
        <input type="text" id="nconst" value={nconst} onChange={(e) => setNconst(e.target.value)} />
      </div>
      <div>
        <label htmlFor="selectEntity">Select Entity to Update:</label>
        <select id="selectEntity" value={selectedEntity} onChange={(e) => setSelectedEntity(e.target.value)}>
          <option value="">Select an entity</option>
          <option value="ordering">Ordering</option>
          <option value="tconst">Tconst</option>
          <option value="category">Category</option>
          <option value="job">Job</option>
          <option value="characters">Characters</option>
          {/* Add more options for other entities you want to update */}
        </select>
      </div>
      <div>
        <label htmlFor="entityValue">Entity Value:</label>
        <input type="text" id="entityValue" value={entityValue} onChange={(e) => setEntityValue(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleUpdate}>Update Title Principals</button>
    </form>
  );
}

export default UpdateTitlePrincipals;
