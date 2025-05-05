<?php
// Database Connection
require_once '../../includes/creds.php';

// Get Search Results
    $search = $_GET['search'] ?? '';
    $squery = "SELECT id, title FROM books WHERE title LIKE :search ORDER BY title ASC";
    $stmt = $pdo->prepare($squery);
    $stmt->execute(['search' => "%$search%"]);
    $search = $stmt->fetchAll();
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
                if (!empty($search)) {
                    echo '<ul>';
                    foreach ($search as $book) {
                        echo '<li>
                                <a href="view_book.php?id=' . htmlspecialchars($book['id']) . '">'
                            . htmlspecialchars($book['title']) .
                            '</a>
                            </li>';
                    }
                    echo '</ul>';
                } else {
                    echo '<p>No books found.</p>';
                }
            ?>
</div>
</div>
</div>

</body>

</html>