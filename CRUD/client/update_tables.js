import React from 'react';
import './App.css';
import './HomePage.css';

function UpdateTables({ onNavigate, onGoBack }) {
  const handleGoToTable = (tableName) => {
    onNavigate(tableName);
  };

  return (
    <div className="container">
      <h1 className="title">List of Tables</h1>
      <div className="box-container">
        <button className="box" onClick={() => handleGoToTable('UpdateNameBasics')}>
          Update Name Basics 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitleAkas')}>
          Update Title Akas 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitleCrew')}>
          Update Title Crew 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitleEpisodes')}>
          Update Title Episodes 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitleRatings')}>
          Update Title Ratings 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitleBasics')}>
          Update Title Basics 
        </button>
        <button className="box" onClick={() => handleGoToTable('UpdateTitlePrincipals')}>
          Update Title Principals 
        </button>
      </div>
      <button onClick={() => onNavigate('home')}>
        Go Back
      </button>
    </div>
  );
}

export default UpdateTables;
