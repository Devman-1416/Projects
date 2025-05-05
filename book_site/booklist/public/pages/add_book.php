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
        <?php //Error messages
            if (isset($_GET['message'])) {
                echo  htmlspecialchars($_GET['message']) . "</p>";
            }

            if (isset($_GET['error'])) {
                echo  htmlspecialchars($_GET['error']) . "</p>";
            }
        ?>
    <h2>Add a New Book</h2>
        <!-- Add Book Form, Leads to insert.php -->
        <form action="../../includes/insert.php" method="POST">


            <label for="title">Title:</label>
            <input type="text" name="title" required><br><br>

            <label for="author">Author:</label>
            <input type="text" name="author" required><br><br>

            <label for="publish_year">Publication Year:</label>
            <input type="number" name="publish_year" min="0" max="9999"><br><br>

            <label for="genre">Genre:</label>
            <input type="text" name="genre"><br><br>

            <label for="status">Status:</label>
            <select name="status">
                <option value="In Progress">In Progress</option>
                <option value="CompletedP">Completed (Physical)</option>
                <option value="CompletedA)">Completed (Audiobook)</option>
                <option value="Abandoned">Abandoned</option>
            </select><br><br>

            <label for="page_count">Page Count:</label>
            <input type="number" name="page_count" min="1"><br><br>

            <label for="listen_time_hours">Listen Time:</label>
            <input type="number" name="listen_time_hours" step="1" min="0" placeholder="Hours">
            <input type="number" name="listen_time_minutes" step="1" min="0" max="59" placeholder="Minutes"><br><br>


            <label for="rating">Rating (out of 5):</label>
            <input type="number" name="rating" step="1" min="0" max="5"><br><br>

            <label for="review">Review:</label>
            <textarea name="review" rows="4" cols="50" placeholder="Write your review here..."></textarea><br><br>

            <button type="submit">Add Book</button>
        </form>
</div>
</div>
</div>

</body>

</html>
