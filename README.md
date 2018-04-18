<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>TP IOT</title>
  <link rel="stylesheet" href="https://stackedit.io/style.css" />
</head>

<body class="stackedit">
  <div class="stackedit__html"><h1 id="mqtt-tp">TP Détecteur de mouvement avec MQTT</h1>
<h2 id="pré-requis-">Pré-requis :</h2>
<ul>
<li><strong>Composant</strong>
<ul>
<li>Carte ESP8266 MOD</li>
<li>Ultrason HC-SR04</li>
</ul>
</li>
<li><strong>Outils</strong>
<ul>
<li>NODE JS pour la partie MQTT</li>
<li>PHP pour l'interface web</li>
<li>MYSQL pour la BDD</li>
<li>MQTT pour facilité la communication entre notre serveur et notre objet connecté </li>
</ul>
</li>
</ul>
<h1 id="commencer">Pour commencer : </h1>
<ul>
<li>Installer un serveur PHP/MSQL en local<br>
installer un service qui fera office de broker MQTT : Le plus connu est Mosquitto</li>
<li>Sur MAC OS X :
<blockquote>
<p>brew install mosquitto</p>
</blockquote>
</li>
<li>Sur Windows :
<blockquote>
<p><a href="http://www.eclipse.org/downloads/download.php?file=/mosquitto/binary/win32/mosquitto-1.4.8-install-win32.exe">http://www.eclipse.org/downloads/download.php?file=/mosquitto/binary/win32/mosquitto-1.4.8-install-win32.exe</a></p>
</blockquote>
</li>
</ul>
<p>tester mosquitto :</p>
<blockquote>
<p>mosquitto_sub -t topic_name</p>
</blockquote>
<p>envoyer une trame mosquitto :</p>
<blockquote>
<p>mosquitto_pub -h localhost -t topic_name -m message</p>
</blockquote>
<p>Lancer le client mqtt :</p>
<blockquote>
<p>npm install</p>
</blockquote>
<blockquote>
<p>node index.js #topic_name sensor/movements</p>
</blockquote>
<h2 id="fonctionnement-de-la-solution">fonctionnement de la solution</h2>

</body>

</html>
