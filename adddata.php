<?php
$server 	= "localhost:3306";	// Change this to correspond with your database port
$username 	= "root";			// Change if use webhost online
$password 	= "";
$DB 		= "qlda";			// database name

$dt = $_REQUEST["data"];		// Get data with variable is "status" sending from Android App 

			$update = new mysqli($server, $username, $password, $DB); // Check database connection
			if ($update->connect_error) {
				die("Connection failed: " . $update->connect_error);
			} 
			
			
			$sql = "insert into esp_data(data)value($dt)";	// Update present status to database
			if ($update->query($sql) === TRUE) {		// If don't put this If , we can't change the value in database
				echo "1";								// Echo "1" , equivalent with send data to App to toast ON
			
			} 
				
			

			
?>