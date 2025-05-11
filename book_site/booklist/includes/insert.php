<?php
// Database Connection
 require_once 'creds.php';

// Taking The data from Add_book
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // The ?? '' ensures that if a value is not set,
    // it defaults to an empty string ('') to prevent errors.
    $title = $_POST['title'] ?? '';
    $author = $_POST['author'] ?? '';
    $publish_year = $_POST['publish_year'] ?? '';
    $genre = $_POST['genre'] ?? '';
    $status = $_POST['status'] ?? '';
    $page_count = $_POST['page_count'] ?? NULL;
    $listen_time_hours = $_POST['listen_time_hours'] ?? NULL;
    $listen_time_minutes = $_POST['listen_time_minutes' ?? NULL];
    $rating = $_POST['rating'] ?? '';
    $review = $_POST['review'] ?? '';

    // Convert To Minutes
    if (!empty($listen_time_hours) || !empty($listen_time_minutes)) {
        $listen_time = ((int) $listen_time_hours) + ((int) $listen_time_minutes / 60);
    } else {
        $listen_time = NULL;
    }
    // Check Rateing
    if ($rating !== NULL && ($rating < 0 || $rating > 5)) {
    $rating = NULL; }

    // Making sure required fields is filled
 if (!empty($title) && !empty($author) && !empty($publish_year) && !empty($status)) {
        try {
            $stmt = $pdo->prepare
            // The placeholders (e.g., :title, :author) prevent SQL injection and improve security.
                ("INSERT INTO books (title, author, publish_year, genre, status, page_count, listen_time, rating, review, created_at)
                VALUES (:title, :author, :publish_year, :genre, :status, :page_count, :listen_time, :rating, :review, NOW())");

            //bindParam() securely links each placeholder to its corresponding PHP variable.
            $stmt->bindParam(':title', $title);
            $stmt->bindParam(':author', $author);
            $stmt->bindParam(':publish_year', $publish_year);
            $stmt->bindParam(':genre', $genre);
            $stmt->bindParam(':status', $status);
            $stmt->bindParam(':page_count', $page_count);
            $stmt->bindParam(':listen_time', $listen_time);
            $stmt->bindParam(':rating', $rating);
            $stmt->bindParam(':review', $review);

            // If successful auto bring back to add_book.php with a message using GET
            if ($stmt->execute()) {
                header("Location: ../public/pages/add_book.php?message=Book+added+successfully");
                exit();
            }
        } catch (PDOException $e) {
            echo "<p>Error: " . $e->getMessage() . "</p>";
            header("Location: ../public/pages/add_book.php?error={$errorMessage}");
        }
    } else {
        echo "<p>Please fill in all required fields.</p>";
        header("Location: ../public/pages/add_book.php?error=" . urlencode("Please fill in all required fields."));
        exit;

    }
}
