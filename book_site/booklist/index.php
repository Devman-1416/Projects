<?php
require_once 'includes/creds.php';
// Query to fetch all book titles
$query = "SELECT id, title FROM books ORDER BY title ASC";
$stmt = $pdo->prepare($query);
$stmt->execute();
$books = $stmt->fetchAll();

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <!-- metadata for the web page -->
    <meta charset="UTF-8">
    <meta name="keywords" content="insert, keywords, here">
    <meta name="description" content="Insert description here">
    <title>Home Page</title>
    <link rel="stylesheet" href="public/assets/styles.css">


</head>

<body>

<div class="navbar">
    <img src="public/assets/whiteBookIcon.png" alt="White Book Icon">
    <a href="public/pages/add_book.php">Add Book</a>
    <a href="#news">About</a>
    <a href="#contact">Home</a>
    <a href="public/pages/search_book.php">Book List</a>

    <!-- Search Bar -->
    <form method="GET" action="public/pages/search_book.php">
    <input type="text" name="search" placeholder="Search books..." value="<?= $_GET['search'] ?? ''?>">
    <button type="submit">Search</button></form>
</div>



<div class="titleBar">

    <div class="container">
        <img class="container__image" src="public/assets/fireplace.jpg" alt="Cave Fire Place">
            <div class="container__text">
            <h1>Hearth Home Libary</h1>
            <p>Welcome to Hearth, your cozy digital library nestled in the heart of a mountain cave.

        </div>
    </div>

</div>

</body>

</html>