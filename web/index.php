<?php
    class FLL {
        session_start();

        ini_set('display_errors', 1);
        ini_set('display_startup_errors', 1);
        error_reporting(E_ALL);

        public $conn;


        
        connectDatabase();
        checkLogin();


        function connectDatabase(){
            $servername = "rdbms.strato.de";
            $username = "dbu2616508";
            $password = "dNiIc1lot7JRNI09nRW9";
            $dbname = "dbs5160395";
            // Create connection
            $this->conn = mysqli_connect($servername, $username, $password, $dbname);

            // Check connection
            if (!$this->conn) {
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
                $result = mysqli_query($this->conn, $sql);

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
    }
?>