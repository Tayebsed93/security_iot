-- phpMyAdmin SQL Dump
-- version 4.7.2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  mer. 18 avr. 2018 à 15:51
-- Version du serveur :  5.6.35
-- Version de PHP :  7.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Base de données :  `5MOC_IOT`
--

-- --------------------------------------------------------

--
-- Structure de la table `iot_datas`
--

CREATE TABLE `iot_datas` (
  `id` int(11) NOT NULL,
  `objet_nom` varchar(250) NOT NULL,
  `date` datetime NOT NULL,
  `valeur` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `iot_datas`
--

INSERT INTO `iot_datas` (`id`, `objet_nom`, `date`, `valeur`) VALUES
(1, 'HC-SR04', '2018-04-18 15:00:00', '30');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `iot_datas`
--
ALTER TABLE `iot_datas`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `iot_datas`
--
ALTER TABLE `iot_datas`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;