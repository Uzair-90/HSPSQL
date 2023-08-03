import React from 'react';
import './HomePage.css';


function HomePage({ onNavigate }) {
  return (
    <div className="container">
      <h1 className="title">Welcome to the Home Page</h1>
      <div className='box-container'>
      <button className="box" onClick={() => onNavigate('tables')}>
        Add data to Tables
      </button>
      <button className="box" onClick={() => onNavigate('read_tables')}>
        Read Tables
      </button>
      <button className="box" onClick={() => onNavigate('update_tables')}>
        Update Tables
      </button>
      <button className="box" onClick={() => onNavigate('delete_tables')}>
        Delete Tables
      </button>
      </div>
    </div>
  );
}

export default HomePage;

