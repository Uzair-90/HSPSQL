import React from 'react';
import './App.css';
import './HomePage.css';

function TableList({ onNavigate, onGoBack }) {
  const handleGoToTable = (tableName) => {
    onNavigate(tableName);
  };

  return (
    <div className="container">
      <h1 className="title">List of Tables</h1>
      <div className="box-container"> {/* Wrap buttons in a container */}
        <button className="box" onClick={() => handleGoToTable('nameBasics')}>
          Name Basics
        </button>
        <button className="box" onClick={() => handleGoToTable('titleAkas')}>
          Title Akas
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleCrew')}>
          Title Crew
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleEpisodes')}>
          Title Episodes
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleRatings')}>
          Title Ratings
        </button>
        <button className="box" onClick={() => handleGoToTable('TitleBasics')}>
          Title Basics
        </button>
        <button className="box" onClick={() => handleGoToTable('TitlePrincipals')}>
          Title Principals
        </button>
      </div>
      <button onClick={() => onNavigate('home')}>
        Go Back
      </button>
    </div>
  );
}

export default TableList;
