<?php
// Database Connection
require_once '../../includes/creds.php';

// Check if id is legit
if (isset($_GET['id']) && is_numeric($_GET['id'])) {
    $book_id = $_GET['id'];

    // find current review for book using id
    try {
        $stmt = $pdo->prepare("SELECT review, status, rating FROM books WHERE id = :id");
        $stmt->bindParam(':id', $book_id, PDO::PARAM_INT);

        $stmt->execute();
        $book = $stmt->fetch();


    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }

}


?>

<!DOCTYPE html>
<html lang="en">

<head>
    <!-- metadata for the web page -->
    <meta charset="UTF-8">
    <meta name="keywords" content="insert, keywords, here">
    <meta name="description" content="Insert description here">
    <title>Add Book</title>
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
    <h2>Edit Book</h2>

    <form action="../../includes/update.php" method="POST">

        <input type="hidden" name="id" value="<?php echo ($_GET['id']); ?>">

        <label for="status">Status:</label>
        <select name="status">
            <option value="In Progress" <?= ($book['status'] == "In Progress") ? 'selected' : '' ?>>In Progress</option>
            <option value="Completed (Physical)" <?= ($book['status'] == "Completed (Physical)") ? 'selected' : '' ?>>Completed
                (Physical)</option>
            <option value="Completed (Audiobook)" <?= ($book['status'] == "Completed (Audiobook)") ? 'selected' : '' ?>>Completed
                (Audiobook)</option>
            <option value="Abandoned" <?= ($book['status'] == "Abandoned") ? 'selected' : '' ?>>Abandoned</option>
        </select><br><br>


        <label for="rating">Rating (out of 5):</label>
        <input value="<?= $book['rating'] ?>" type="number" name="rating" step="1" min="0" max="5"><br><br>

        <!-- Fill box with current review-->
        <label for="review">Review:</label>
        <textarea name="review" rows="4" cols="50" placeholder="Write your review here...">
        <?php echo htmlspecialchars($book['review']); ?>
        </textarea><br><br>

        <button type="submit">Update Book</button>
    </form>
</div>
</div>
</div>

</body>

</html>