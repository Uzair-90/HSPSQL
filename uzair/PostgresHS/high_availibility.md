# High availibility using pg-pool ii

In this tutorial we will have one worker node and one master node this scaling is performed via
replication. We will have a replica of the master database which will run all insert,delete and 
update queries while a worker node which will run all the select queries.

## Setting up the instances

Use the the command line argument:

```cmd
initdb -D /path

```
The above command will make a postgres instance but make sure that you have postgres installed
on your machine.
Make two instances one master and one worker.

## Configuration in master instance

After making the instance we will do some modification in the configuration of file of the created instance.

```cmd
nano postgresql.conf
```
Change the listen address parameter for that just seach in the file using cntrl+w and 
listen_address press enter.
By default it will be set to localhost change it to * so that it can listen on network also.

Change the port address to 5433 or any other suitable port address.

Exit the nano that's all the changes you need in master instance for now.

To start the database use the following command inside the directory.

```cmd
pg_ctl -D . start
```
After the starting the server we will create a replication user to do this we will first need to connect to the server in the following way:

```cmd
psql --port=5433 postgres
```
After connection create the user in the following manner:

```cmd
create user repuser replication;
```
After creating the user we will need to configure the user for connections to do this type:

```cmd
nano pg_hba.conf
```
In the pg_hba.conf file copy the following line and paste it again:

```cmd
host    all             all             127.0.0.1/32            trust
```
and change the second "all" to repuser which you created earlier for replication.

```cmd
host    all             repuser             127.0.0.1/32            trust
``` 
After performing the above steps jsut restart the server:

```cmd
pg_ctl -D . restart
```

Now once you are done with setting your master node you will have to create a replica using 
pg_basebackup command. Do it like this:

```cmd
pg_basebackup -h localhost -U repuser --checkpoint=fast \
-D /path/to/create/replica -R --slot=my_replica -C --port=5433
```
This will create your worker or replication node.

Now change directory to the path where you created the replication db instance.

## Configuration in replica

Type the following command:

```cmd
nano postgresql.conf
```
Seach for the port and the change the port address to 5434.

Now start the replica server using:

```cmd
pg_ctl -D . start
```
# Setting up pg-pool 2 to handle queries

First of all install pgpool 2 if you are using mac os just type:

```cmd
brew install pgpool-ii
```
after the installtion is done type:

```cmd
cd /usr/local/etc
```
After that type:

```cmd
nano pgpool.conf
```
Inside this configuration file you will have to make some changes to make pgpool ready for your work.

First of all you will have to change the listen address just seach for listen_address and change it to * from localhost to make it able listen on any address.
Check for backend connection settings and setup your backend instance.
In this section change host to localhost.
change the port number accordingly for master as well as worker.
In backend_data_directory enter the correct path.

After that press crtl+w and search for the log_statement there turn on the log. Also enable the log_per_statement option.
Change the pid_file_name relative to the pgpool installation.
Seach for sr_check_user and set it to repuser.
Set the health check to run every 10 seconds. The health_check_user will the user that you created for the replication.

Now to run pgpool just type:

```cmd
pgpool -n &
```
This will run the pgpool along printing the log messages on the terminal.

After running the pgpool just open any other window and start a psql instance by connecting to port 9999 like:

```cmd
psql -p 9999 postgres
```
Now create any random table with any attributes and note the pgpool log messages it will show that the command is executed on the primary node.

After you established your connection to pgpool successfully you can see the log messages on pgpool window but if you want to redirect those log messages to some file use the following method this will redirect all the standard stream erros and logs to to a file created on desktop or you can also choose any other desination:

```cmd
pgpool -n > /Users/khan/desktop/pgpool.log 2>&1 & 
```

This will run pgpool in the fore-ground and will also redirect the messages to the file pgpool.log.


## Configuring pgpool for failover

If your master node fails then all your insert, update or delete queries will lost because the system will not consider them as they are only associated with master in this case we must make a standby or worker node as master or primary node.

To make this go to your master db instance and type:

```cmd
nano postgresql.conf
```
Search for the synchronous_commit parameter and set it to remote apply.
This process will make sure that the worker nodes will wait until the master has recieved all the select, update or delete queries and processed them. So, this will make sure that all the changes are visible to worker nodes.

Also change the synchoronous_standby_names to * so that it can apply it to all possible worker nodes.

After this we will set the wal_log_hints which is necessary to bring all the fail masters.
Search for wal_log_hints and set it to on.
Now just do a restart:

```cmd
pr_ctl -D . restart
```
Now to configure auto failover you will need a script that will take two or more arguments according the number of master and worker nodes that are connected for now we will consider that there is only one master node and one worker node use the following script for it:

```cmd
#!/bin/sh

failed_node="$1"
trigger_file="$2"

if [ "$failed_node" = "1" ]; then
  exit 0
fi

touch "$trigger_file"
exit 0

```
This script is taking two command line arguments and checking whether the master node is failed or not on that basis it will decide to touch trigger file or not.

To make configuration go to pgpool configuration file like:

```cmd
nano pgpool.conf
```

Inside this file search for failover_command and specify the location of the script that we created earlier.
Do it like this:

```cmd
failover_command = '/Users/khan/desktop/failover.sh %d /Users/khan/desktop/replication/worker/down.trg'
```
The above command will create a file down.rig just save and exit.

## Configuring postgresql worker or replica instance

Chnage your working directory to replica instance and type:

```cmd
nano postgresql.conf
```
Now search for promote_trigger_file  and give the path of the created file.

















