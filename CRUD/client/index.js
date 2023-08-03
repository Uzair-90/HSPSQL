import React, { useState } from 'react';
import ReactDOM from 'react-dom';
import './App.css';
import NameBasics from './components/read/namebasics';
import TitleAkas from './components/read/titleakas';
import HomePage from './home';
import TitlePrincipals from './components/read/title_principals';
import TitleRatings from './components/read/title_ratings';
import TitleEpisodes from './components/read/title_episodes';
import TitleCrew from './components/read/title_crew';
import TitleBasics from './components/read/title_basics';
import TableList from './table_list';
import NameBasicsDisplay from './components/display/display_namebasics';
import TitleAkasDisplay from './components/display/display_title_akas';
import TitleCrewDisplay from './components/display/display_title_crew';
import TitleRatingsDisplay from './components/display/display_title_ratings';
import TitleBasicsDisplay from './components/display/display_title_basics';
import TitlePrincipalsDisplay from './components/display/display_title_principals';
import TitleEpisodesDisplay from './components/display/display_title_episodes';
import ReadTabels from './read_tables';
import UpdateNameBasics from './components/update/update_namebasics';
import UpdateTitleAkas from './components/update/update_title_akas';
import UpdateTitleCrew from './components/update/update_title_crew';
import UpdateTitleBasics from './components/update/update_title_basics';
import UpdateTitlePrincipals from './components/update/update_title_principals';
import UpdateTitleRatings from './components/update/update_title_ratings';
import UpdateTitleEpisodes from './components/update/update_title_episodes';
import UpdateTables from './update_tables';
import DeleteNameBasics from './components/delete/delete_name_basics';
import DeleteTitleAkas from './components/delete/delete_title_akas';
import DeleteTitlePrincipals from './components/delete/delete_title_principals';
import DeleteTitleBasics from './components/delete/delete_title_basics';
import DeleteTitleCrew from './components/delete/delete_title_crew';
import DeleteTitleEpisodes from './components/delete/delete_title_episodes';
import DeleteTitleRatings from './components/delete/delete_title_ratings';
import DeleteTables from './delete_tabels';

const root = ReactDOM.createRoot(document.getElementById('root'));

function App() {
  const [currentPage, setCurrentPage] = useState('home');
  const [previousPage, setPreviousPage] = useState(null);

  const handleNavigation = (page) => {
    setPreviousPage(currentPage);
    setCurrentPage(page);
  };

  const handleGoBack = () => {
    if (previousPage) {
      setCurrentPage(previousPage);
      setPreviousPage(null);
    }
  };

  return (
    <React.StrictMode>
      
      {currentPage === 'home' && <HomePage onNavigate={(page) => setCurrentPage(page)} />}
      {currentPage === 'tables' && <TableList onNavigate={handleNavigation} onGoBack={handleGoBack} />}
      {currentPage === 'nameBasics' && <NameBasics />}
      {currentPage === 'titleAkas' && <TitleAkas />}
      {currentPage === 'TitlePrincipals' && <TitlePrincipals />}
      {currentPage === 'TitleRatings' && <TitleRatings />}
      {currentPage === 'TitleEpisodes' && <TitleEpisodes />}
      {currentPage === 'TitleCrew' && <TitleCrew />}
      {currentPage === 'TitleBasics' && <TitleBasics />}
      {currentPage === 'read_tables' && <ReadTabels onNavigate={handleNavigation} onGoBack={handleGoBack} />}
      {currentPage === 'NameBasicsDisplay' && <NameBasicsDisplay />}
      {currentPage === 'TitleAkasDisplay' && <TitleAkasDisplay />}
      {currentPage === 'TitlePrincipalsDisplay' && <TitlePrincipalsDisplay />}
      {currentPage === 'TitleRatingsDisplay' && <TitleRatingsDisplay />}
      {currentPage === 'TitleEpisodesDisplay' && <TitleEpisodesDisplay />}
      {currentPage === 'TitleCrewDisplay' && <TitleCrewDisplay />}
      {currentPage === 'TitleBasicsDisplay' && <TitleBasicsDisplay />} 
      {currentPage === 'update_tables' && <UpdateTables onNavigate={handleNavigation} onGoBack={handleGoBack} />}
      {currentPage === 'UpdateNameBasics' && <UpdateNameBasics />}
      {currentPage === 'UpdateTitleAkas' && <UpdateTitleAkas />}
      {currentPage === 'UpdateTitlePrincipals' && <UpdateTitlePrincipals />}
      {currentPage === 'UpdateTitleRatings' && <UpdateTitleRatings />}
      {currentPage === 'UpdateTitleEpisodes' && <UpdateTitleEpisodes />}
      {currentPage === 'UpdateTitleCrew' && <UpdateTitleCrew />}
      {currentPage === 'UpdateTitleBasics' && <UpdateTitleBasics />}
      {currentPage === 'delete_tables' && <DeleteTables onNavigate={handleNavigation} onGoBack={handleGoBack} />}
      {currentPage === 'DeleteNameBasics' && <DeleteNameBasics />}
      {currentPage === 'DeleteTitleAkas' && <DeleteTitleAkas />}
      {currentPage === 'DeleteTitlePrincipals' && <DeleteTitlePrincipals />}
      {currentPage === 'DeleteTitleRatings' && <DeleteTitleRatings />}
      {currentPage === 'DeleteTitleEpisodes' && <DeleteTitleEpisodes />}
      {currentPage === 'DeleteTitleCrew' && <DeleteTitleCrew />}
      {currentPage === 'DeleteTitleBasics' && <DeleteTitleBasics />}
      
      {currentPage !== 'home' && currentPage !== 'tables' && currentPage !== 'read_tables' && currentPage !== 'update_tables' && currentPage !== 'delete_tables' && (
  <button onClick={handleGoBack}>Go Back</button>
)}

      
    </React.StrictMode>
  );
}

root.render(<App />);
