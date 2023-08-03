import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function UpdateTitleCrew() {
  const [tconst, setTconst] = useState('');
  const [selectedEntity, setSelectedEntity] = useState('');
  const [entityValue, setEntityValue] = useState('');

  const handleUpdate = async () => {
    try {
      const data = { [selectedEntity]: entityValue };
      const response = await axios.put(`http://localhost:3001/api/title_crew/${tconst}`, data);

      // Handle success, show a success message or perform any other actions needed
      console.log('Update successful:', response.data);

      // Reset the form after successful update
      setTconst('');
      setSelectedEntity('');
      setEntityValue('');
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      console.error('Error updating title_crew data:', error);
    }
  };

  return (
    <form>
      <h2>Update Title Crew</h2>
      <div>
        <label htmlFor="tconst">Tconst:</label>
        <input type="text" id="tconst" value={tconst} onChange={(e) => setTconst(e.target.value)} />
      </div>
      <div>
        <label htmlFor="selectEntity">Select Entity to Update:</label>
        <select id="selectEntity" value={selectedEntity} onChange={(e) => setSelectedEntity(e.target.value)}>
          <option value="">Select an entity</option>
          <option value="directors">Directors</option>
          <option value="writers">Writers</option>
          {/* Add more options for other entities you want to update */}
        </select>
      </div>
      <div>
        <label htmlFor="entityValue">Entity Value:</label>
        <input type="text" id="entityValue" value={entityValue} onChange={(e) => setEntityValue(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleUpdate}>Update Title Crew</button>
    </form>
  );
}

export default UpdateTitleCrew;
