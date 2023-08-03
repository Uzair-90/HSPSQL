import React from 'react';
import './App.css';
import './HomePage.css';

function DeleteTables({ onNavigate, onGoBack }) {
  const handleGoToTable = (tableName) => {
    onNavigate(tableName);
  };

  return (
    <div className="container">
      <h1 className="title">List of Tables</h1>
      <div className="box-container">
        <button className="box" onClick={() => handleGoToTable('DeleteNameBasics')}>
          Delete Name Basics 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitleAkas')}>
          Delete Title Akas 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitleCrew')}>
          Delete Title Crew 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitleEpisodes')}>
          Delete Title Episodes 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitleRatings')}>
          Delete Title Ratings 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitleBasics')}>
          Delete Title Basics 
        </button>
        <button className="box" onClick={() => handleGoToTable('DeleteTitlePrincipals')}>
          Delete Title Principals 
        </button>
      </div>
      <button  onClick={() => onNavigate('home')}>
        Go Back
      </button>
    </div>
  );
}

export default DeleteTables;
