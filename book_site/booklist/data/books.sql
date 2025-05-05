-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 03, 2025 at 12:03 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `books`
--

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `author` varchar(255) NOT NULL,
  `publish_year` year(4) DEFAULT NULL,
  `genre` varchar(100) DEFAULT NULL,
  `status` varchar(100) DEFAULT 'In Progress',
  `page_count` int(10) UNSIGNED DEFAULT NULL,
  `listen_time` int(10) UNSIGNED DEFAULT NULL,
  `rating` int(11) DEFAULT NULL CHECK (`rating` between 1 and 5),
  `review` text DEFAULT NULL,
  `created_at` date NOT NULL,
  `updated_at` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`id`, `title`, `author`, `publish_year`, `genre`, `status`, `page_count`, `listen_time`, `rating`, `review`, `created_at`, `updated_at`) VALUES
(1, 'The Name of The Wind', 'Patrick Rothfuss', '2007', 'Fantasy Fiction', 'Completed (Physical)', 722, NULL, 4, 'This is a test review', '2025-02-19', '2025-02-19 05:00:00'),
(2, 'The Wise Man\'s Fear', 'Patrick Rothfuss', '2011', 'Fantasy Fiction', 'Completed (Physical)', 1107, NULL, 4, 'Test R', '2025-02-19', '2025-02-19 05:00:00'),
(3, 'The Courage to be Disliked', 'Ichiro Kishimi and Fumitake Koga', '2013', 'Self Help', 'In Progress', 270, NULL, 4, 'The way it was written, as a conversation between a young pessimist and philosopher, was a creative way to help explain Alfred Adler phycology. The material itself was enlightening and made me self reflect. The beginning was a struggle, it annoyed me at first but halfway through the it just `clicks`.   ', '2025-02-20', '0000-00-00 00:00:00'),
(4, 'Attached', 'Amir Levine, M.D, and Rachel S.F Heller, M.A.', '2010', 'Self Help', 'In Progress', 304, NULL, 4, 'When my ex left me, I started looking for the reason, a answer to what happened. My search lead me to this book. Another piece of literature that helped me heal my heartbreak by reflecting on mine and her attachment style. It is something I will go back to in the future to see how my opinion changes when my heart is fully healed.', '2025-02-20', '0000-00-00 00:00:00'),
(5, 'Raptor Red', 'Robert T. Bakker', '1995', 'Fiction', 'Completed (Audiobook)', NULL, 172, 4, '                This was a really short yet fun experience. The audio book, narrated by Megan Gallagher used many sound effects and background music to set the scenes. Writing a story that\'s not just talking dinosaurs but making them feel like real animals is something I never even seen done in a written format.                                         ', '2025-02-20', '2025-03-04 19:45:36'),
(6, 'Atomic Habits: An easy & Proven Way to Build Good Habits & Break Bad Ones', 'James Clear', '2018', 'Self Help', '', NULL, 335, 5, 'Very informative', '2025-02-22', '0000-00-00 00:00:00'),
(7, 'A Little Life', 'Hanya Yanagihara', '2015', 'Novel', 'Abandoned', 832, NULL, 2, '        I couldn\'t read much more, after getting to page 72 I stopped.        ', '2025-02-25', '2025-03-04 19:44:49'),
(20, 'test', 'test', '0000', '', 'In Progress', NULL, NULL, 3, 'This is a update         ', '2025-02-22', '2025-03-01 01:08:37'),
(21, 'Hello World Stuff ', 'Me', '2025', 'tech', '', 1122, 33, NULL, '', '2025-02-24', '0000-00-00 00:00:00'),
(228, 'The Hobbit', 'J.R.R Tolkien', '1937', 'Fantasy', 'Completed(A)', 0, 10, 5, 'My first book ever read, and my comfort book forever. I love you', '2025-03-03', '2025-03-04 19:30:03');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `user_id` int(11) NOT NULL,
  `user` varchar(50) NOT NULL,
  `password` varchar(100) NOT NULL,
  `date` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `books`
--
ALTER TABLE `books`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=229;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
