import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function DeleteTitleAkas() {
  const [titleId, setTitleId] = useState('');
  const [message, setMessage] = useState('');

  const handleDelete = async () => {
    try {
      const response = await axios.delete(`http://localhost:3001/api/title_akas/${titleId}`);

      // Handle success, show a success message or perform any other actions needed
      setMessage('Delete successful');
      console.log('Delete successful:', response.data);
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      setMessage('Error deleting data');
      console.error('Error deleting title_akas data:', error);
    }
  };

  return (
    <form>
      <h2>Delete Title Akas</h2>
      <div>
        <label htmlFor="titleId">Enter Title ID to Delete:</label>
        <input type="text" id="titleId" value={titleId} onChange={(e) => setTitleId(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleDelete}>Delete Title Akas</button>
      <div>{message}</div>
    </form>
  );
}

export default DeleteTitleAkas;
