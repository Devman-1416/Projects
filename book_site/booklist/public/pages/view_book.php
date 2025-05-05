<?php
require_once '../../includes/creds.php';

// Query to fetch all book titles
// Check if Id is safe

$id = ($_GET['id']);
if ($id !== NULL) {
    $query = "SELECT title, author, publish_year, genre, status, page_count, listen_time, rating, review, created_at
        FROM books Where id = $id";
    $stmt = $pdo->prepare($query);
    $stmt->execute();
    $book = $stmt->fetch();
}

// Get Listen Time Hours and Min
$hours = floor($book['listen_time'] / 60);
$minutes = $book['listen_time'] % 60;

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <!-- metadata for the web page -->
    <meta charset="UTF-8">
    <meta name="keywords" content="insert, keywords, here">
    <meta name="description" content="Insert description here">
    <title>Home Page</title>
    <link rel="stylesheet" href="../assets/styles.css">


</head>

<body>
<!-- Top Nav Bar -->
<div class="navbar">
    <img src="../assets/whiteBookIcon.png" alt="White Book Icon">
    <a href="add_book.php">Add Book</a>
    <a href="#news">About</a>
    <a href="../../index.php">Home</a>
    <a href="search_book.php">Book List</a>

    <!-- Search Bar -->
    <form method="GET" action="search_book.php">
    <input type="text" name="search" placeholder="Search books..." value="<?= $_GET['search'] ?? '' ?>">
        <button type="submit">Search</button>
    </form>
</div>

<div class="titleBar">
    <div class="container">
    <img class="container__image" src="../assets/fireplace.jpg" alt="Cave Fire Place">
    <div class="container__text">

    <?php
    // Format Better
    // List Book info
        echo '<p><strong>Title:</strong> ' . $book['title'] . '</p>';
        echo '<p><strong>Author:</strong> ' . $book['author'] . '</p>';
        echo '<p><strong>Year Published:</strong> ' . $book['publish_year'] . '</p>';
        echo '<p><strong>Genre:</strong> ' . $book['genre'] . '</p>';
        echo '<p><strong>Status:</strong> ' . $book['status'] . '</p>';
        // if statements for page vs audio
        if ($book['page_count'] != NULL) {
            echo '<p><strong>Page Count:</strong> ' . $book['page_count'] . '</p>';}
        else {
            echo '<p><strong>Listen Time:</strong> ' . $hours . ' hr ' . $minutes . ' min</p>';
        }
        echo '<p><strong>Rating:</strong> ' . $book['rating'] . '</p>';
        echo '<p><strong>Review:</strong> ' . $book['review'] . '</p>';
        echo '<p><strong>Book Added:</strong> ' . $book['created_at'] . '</p>';

        // Link to update_book
        echo '<br><br> <a href="update_book.php?id=' . htmlspecialchars($id) . '">Update Book</a>';

    ?>
</div>
</div>
</div>



</body>

</html>