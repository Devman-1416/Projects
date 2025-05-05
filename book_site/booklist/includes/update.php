<?php
// Database Connection
 require_once 'creds.php';

// Taking The data from Add_book
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // The ?? '' ensures that if a value is not set,
    // it defaults to an empty string ('') to prevent errors.
    $id = $_POST['id'];
    $status = $_POST['status'] ?? '';
    $rating = $_POST['rating'] ?? '';
    $review = $_POST['review'] ?? '';

    // Check if ID is valid
    if (empty($id)) {
        echo "<p>Error: Missing book ID.</p>";
        echo '<a href="../public/pages/update_book.php">Go Back</a>';
        exit();
    }

    // Check Rateing
    if ($rating !== NULL && ($rating < 0 || $rating > 5)) {
        $rating = NULL;
    }

    try {
        // Prepare update query
        $stmt = $pdo->prepare(
            "UPDATE books
             SET status = :status, rating = :rating, review = :review
             WHERE id = :id"
        );

        // Bind parameters
        $stmt->bindParam(':id', $id, PDO::PARAM_INT);
        $stmt->bindParam(':status', $status, PDO::PARAM_STR);
        $stmt->bindParam(':rating', $rating, PDO::PARAM_INT);
        $stmt->bindParam(':review', $review, PDO::PARAM_STR);

        // Execute the update query
        if ($stmt->execute()) {
            // Redirect back to update_book.php with success message
            header("Location: ../index.php?message=Book+updated+successfully");
            exit();
        } else {
            echo "<p>Error updating book.</p>";
            echo '<a href="../index.php">Go Back</a>' . htmlspecialchars($id) . '">Go Back</a>';
        }
    } catch (PDOException $e) {
        echo "<p>Error: " . $e->getMessage() . "</p>";
        echo '<a href="../index.php">Go Back</a>' . htmlspecialchars($id) . '">Go Back</a>';
    }
} else {
    echo "<p>Invalid request.</p>";
    echo '<a href="../index.php">Go Back</a>';
}