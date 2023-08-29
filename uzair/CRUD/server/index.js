const express = require('express');
const { Client } = require('pg');
const bodyParser = require('body-parser');
const cors = require('cors');
const cli = require('nodemon/lib/cli');
const app = express();
const port = 3001;

app.use(cors());
app.use(bodyParser.json());
app.use(express.json());

const client = new Client({
  user: 'khan',
  host: 'localhost',
  port: 5432,
  database: 'postgres',
});

client.connect()
  .then(() => {
    console.log('Connected to the PostgreSQL database!');
  })
  .catch((err) => {
    console.error('Error connecting to the PostgreSQL database:', err);
  });

// The following code is just to execute a query to check connection results.
/* client.query('SELECT * FROM name_basics limit 5', (err, result) => {
  if (err) {
    console.error('Error executing query:', err);
    return;
  }

  // Process the query result
  console.log('Query result:', result.rows);
}); */

process.on('SIGINT', () => {
  client.end();
  process.exit();
});

app.get('/', (req, res) => {
  res.send('Your server is running on port 3001');
});

app.post('/api/name_basics', async (req, res) => {
  const { birthYear, deathYear, nconst, primaryName, primaryProfession, knownForTitles } = req.body;

  // Convert birthYear and deathYear to integers or set them to NULL if empty or missing
  const parsedBirthYear = birthYear !== '' ? parseInt(birthYear) : null;
  const parsedDeathYear = deathYear !== '' ? parseInt(deathYear) : null;

  try {
    await client.query(
      'INSERT INTO name_basics (birth_year, death_year, nconst, primary_name, primary_profession, known_for_titles) VALUES ($1, $2, $3, $4, $5, $6)',
      [parsedBirthYear, parsedDeathYear, nconst, primaryName, primaryProfession, knownForTitles]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating name_basics:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});


app.post('/api/title_akas', async (req, res) => {
  const { ordering, isOriginalTitle, region, titleId, types, attributes, language, title } = req.body;

  // Convert ordering to integer
  const parsedOrdering = parseInt(ordering);

  try {
    await client.query(
      'INSERT INTO title_akas (ordering, is_original_title, region, title_id, types, attributes, language, title) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)',
      [parsedOrdering, isOriginalTitle, region, titleId, types, attributes, language, title]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_akas:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});



app.post('/api/title_principals', async (req, res) => {
  const { ordering, tconst, nconst, category, job, characters } = req.body;

  // Convert ordering to an integer or set it to NULL if empty or missing
  const parsedOrdering = ordering !== '' ? parseInt(ordering) : null;

  try {
    await client.query(
      'INSERT INTO title_principals (ordering, tconst, nconst, category, job, characters) VALUES ($1, $2, $3, $4, $5, $6)',
      [parsedOrdering, tconst, nconst, category, job, characters]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_principals:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});



app.post('/api/title_ratings', async (req, res) => {
  const { averageRating, numVotes, tconst } = req.body;

  try {
    await client.query(
      'INSERT INTO title_ratings (average_rating, num_votes, tconst) VALUES ($1, $2, $3)',
      [averageRating, numVotes, tconst]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_ratings:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});



app.post('/api/title_episodes', async (req, res) => {
  const { seasonNumber, episodeNumber, tconst, parentTconst } = req.body;

  try {
    await client.query(
      'INSERT INTO title_episodes (season_number, episode_number, tconst, parent_tconst) VALUES ($1, $2, $3, $4)',
      [seasonNumber, episodeNumber, tconst, parentTconst]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_episodes:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


app.post('/api/title_crew', async (req, res) => {
  const { tconst, directors, writers } = req.body;

  try {
    await client.query(
      'INSERT INTO title_crew (tconst, directors, writers) VALUES ($1, $2, $3)',
      [tconst, directors, writers]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_crew:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


app.post('/api/title_basics', async (req, res) => {
  const { startYear, endYear, runtimeMinutes, isAdult, tconst, genres, titleType, primaryTitle, originalTitle } = req.body;

  try {
    await client.query(
      'INSERT INTO title_basics (startYear, endYear, runtimeMinutes, isAdult, tconst, genres, titleType, primaryTitle, originalTitle) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)',
      [startYear, endYear, runtimeMinutes, isAdult, tconst, genres, titleType, primaryTitle, originalTitle]
    );
    res.sendStatus(201); // Send a success response
  } catch (error) {
    console.error('Error creating title_basics:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//from this onward its get apis which will get the data from tabels and will display it
app.get('/api/name_basics', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM name_basics OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching name_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// API endpoint to fetch data from the title_akas table with pagination
app.get('/api/title_akas', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_akas OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_akas data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//Api endpoint to fetch title_crew data
app.get('/api/title_crew', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_crew OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_crew data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//API endpoint to display title_ratings
app.get('/api/title_ratings', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_ratings OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_ratings data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//API endpoint to display the title_basics data
app.get('/api/title_basics', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_basics ORDER BY tconst OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//API endpoint to display the data of title_principals

app.get('/api/title_principals', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_principals ORDER BY tconst, nconst, category, job OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_principals data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//API endpoint to display the data of title_episodes

app.get('/api/title_episodes', async (req, res) => {
  const { offset, limit } = req.query;
  const parsedOffset = parseInt(offset);
  const parsedLimit = parseInt(limit);

  try {
    const queryResult = await client.query(
      'SELECT * FROM title_episodes ORDER BY tconst, season_number, episode_number OFFSET $1 LIMIT $2',
      [parsedOffset, parsedLimit]
    );
    res.status(200).json(queryResult.rows);
  } catch (error) {
    console.error('Error fetching title_episodes data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


//from this onward we are updating tables.

// Update name_basics entity by nconst
app.put('/api/name_basics/:nconst', async (req, res) => {
  const nconst = req.params.nconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE name_basics SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(updateObject[column]);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE nconst = $${values.length + 1}`;
  values.push(nconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating name_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Update title_akas entity by title_id
app.put('/api/title_akas/:titleId', async (req, res) => {
  const titleId = req.params.titleId;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_akas SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(updateObject[column]);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE title_id = $${values.length + 1}`;
  values.push(titleId);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_akas data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});



// Update title_crew entity by tconst
app.put('/api/title_crew/:tconst', async (req, res) => {
  const tconst = req.params.tconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_crew SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    // Check if the value is an array, if not, convert it to an array with one element
    const value = Array.isArray(updateObject[column]) ? updateObject[column] : [updateObject[column]];
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(value);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE tconst = $${values.length + 1}`;
  values.push(tconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_crew data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Update title_basics entity by tconst
app.put('/api/title_basics/:tconst', async (req, res) => {
  const tconst = req.params.tconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_basics SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    // Check if the column is 'genres' and format the array literal correctly
    if (column === 'genres') {
      updateQuery += ` ${column} = ARRAY[$${index + 1}]::text[],`;
      values.push(updateObject[column]);
    } else {
      updateQuery += ` ${column} = $${index + 1},`;
      values.push(updateObject[column]);
    }
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE tconst = $${values.length + 1}`;
  values.push(tconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Update title_principals entity by nconst
app.put('/api/title_principals/:nconst', async (req, res) => {
  const nconst = req.params.nconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_principals SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(updateObject[column]);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE nconst = $${values.length + 1}`;
  values.push(nconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_principals data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Update title_ratings entity by tconst
app.put('/api/title_ratings/:tconst', async (req, res) => {
  const tconst = req.params.tconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_ratings SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(updateObject[column]);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE tconst = $${values.length + 1}`;
  values.push(tconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_ratings data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Update title_episodes entity by tconst
app.put('/api/title_episodes/:tconst', async (req, res) => {
  const tconst = req.params.tconst;
  const updateObject = req.body; // Entity and value to be updated

  let updateQuery = `UPDATE title_episodes SET`;
  const values = []; // Values to be used in the query

  const updateColumns = Object.keys(updateObject).filter((column) => column !== 'updated_at');
  updateColumns.forEach((column, index) => {
    updateQuery += ` ${column} = $${index + 1},`;
    values.push(updateObject[column]);
  });

  updateQuery = updateQuery.slice(0, -1); // Remove the trailing comma
  updateQuery += ` WHERE tconst = $${values.length + 1}`;
  values.push(tconst);

  try {
    await client.query(updateQuery, values);
    res.status(200).json({ message: 'Update successful' });
  } catch (error) {
    console.error('Error updating title_episodes data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

//from this onward the apis are for deleting rows from tables.

//delete from name_basics using nconst
app.delete('/api/name_basics/:nconst', async (req, res) => {
  const nconst = req.params.nconst;

  try {
    await client.query('DELETE FROM name_basics WHERE nconst = $1', [nconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting name_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_akas row by title_id
app.delete('/api/title_akas/:titleId', async (req, res) => {
  const titleId = req.params.titleId;

  try {
    await client.query('DELETE FROM title_akas WHERE title_id = $1', [titleId]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_akas data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_principals row by tconst
app.delete('/api/title_principals/:tconst', async (req, res) => {
  const tconst = req.params.tconst;

  try {
    await client.query('DELETE FROM title_principals WHERE tconst = $1', [tconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_principals data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_basics row by tconst
app.delete('/api/title_basics/:tconst', async (req, res) => {
  const tconst = req.params.tconst;

  try {
    await client.query('DELETE FROM title_basics WHERE tconst = $1', [tconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_basics data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_crew row by tconst
app.delete('/api/title_crew/:tconst', async (req, res) => {
  const tconst = req.params.tconst;

  try {
    await client.query('DELETE FROM title_crew WHERE tconst = $1', [tconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_crew data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_episodes row by tconst
app.delete('/api/title_episodes/:tconst', async (req, res) => {
  const tconst = req.params.tconst;

  try {
    await client.query('DELETE FROM title_episodes WHERE tconst = $1', [tconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_episodes data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});


// Delete title_ratings row by tconst
app.delete('/api/title_ratings/:tconst', async (req, res) => {
  const tconst = req.params.tconst;

  try {
    await client.query('DELETE FROM title_ratings WHERE tconst = $1', [tconst]);
    res.status(200).json({ message: 'Delete successful' });
  } catch (error) {
    console.error('Error deleting title_ratings data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});