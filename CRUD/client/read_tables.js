import React from 'react';
import './App.css';
import './HomePage.css';

function ReadTables({ onNavigate, onGoBack }) {
  const handleGoToTable = (tableName) => {
    onNavigate(tableName);
  };

  return (
    <div className="container">
      <h1 className="title">List of Tables</h1>
      <div className="box-container">
        <button className="box" onClick={() => handleGoToTable('NameBasicsDisplay')}>
          Name Basics Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleAkasDisplay')}>
          Title Akas Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleCrewDisplay')}>
          Title Crew Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleEpisodesDisplay')}>
          Title Episodes Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleRatingsDisplay')}>
          Title Ratings Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleBasicsDisplay')}>
          Title Basics Display
        </button>
        <button className="box" onClick={() => handleGoToTable('TitlePrincipalsDisplay')}>
          Title Principals Display
        </button>
      </div>
      <button  onClick={() => onNavigate('home')}>
        Go Back
      </button>
    </div>
  );
}

export default ReadTables;
