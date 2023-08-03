import React, { useState } from 'react';
import axios from 'axios';
import '../../App.css';

function DeleteNameBasics() {
  const [nconst, setNconst] = useState('');
  const [message, setMessage] = useState('');

  const handleDelete = async () => {
    try {
      const response = await axios.delete(`http://localhost:3001/api/name_basics/${nconst}`);

      // Handle success, show a success message or perform any other actions needed
      setMessage('Delete successful');
      console.log('Delete successful:', response.data);
    } catch (error) {
      // Handle error, show an error message or perform any other actions needed
      setMessage('Error deleting data');
      console.error('Error deleting name_basics data:', error);
    }
  };

  return (
    <form>
      <h2>Delete Name Basics</h2>
      <div >
        <label htmlFor="nconst">Enter Nconst to Delete:</label>
        <input type="text" id="nconst" value={nconst} onChange={(e) => setNconst(e.target.value)} />
      </div>
      <button className='glow-on-hover' onClick={handleDelete}>Delete Name Basics</button>
      <div>{message}</div>
    </form>
  );
}

export default DeleteNameBasics;
