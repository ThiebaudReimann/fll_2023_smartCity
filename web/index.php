<?php
    session_start();

    $servername = "rdbms.strato.de";
    $username = "dbu2616508";
    $password = "dNiIc1lot7JRNI09nRW9";
    $dbname = "dbs5160395";


    
    connectDatabase();
    checkLogin();


    function connectDatabase(){
        // Create connection
        $conn = mysqli_connect($servername, $username, $password, $dbname);

        // Check connection
        if (!$conn) {
            die("Connection failed: " . mysqli_connect_error());
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