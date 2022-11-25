<?php
    session_start();

    $servername = "localhost";
    $username = "username";
    $password = "password";

    
    connectDatabase();
    checkLogin();

    

    mysqli_close($conn);

    function connectDatabase(){
        // Create connection
        $conn = mysqli_connect($servername, $username, $password);

        // Check connection
        if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
        } 
        echo "Connected successfully";
    }
    function checkLogin(){
        if(isset($_SESSION["id"])){
            //already logged in
        }else{
            $username = $_POST["username"];
            $password = $_POST["password"];

            $sql = "SELECT id FROM users";
            $result = mysqli_query($conn, $sql);

            if (mysqli_num_rows($result) > 0){
                while($row = mysqli_fetch_assoc($result)) {
                    echo "id: " . $row["id"]. "<br>";
                    $_SESSION["id"] = $row["id"];
                }
            }else{
                echo "login wrong <br>";
                unset($_SESSION["id"]);
            }
        }
    }
?>