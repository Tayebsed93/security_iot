<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
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
</ul>
<p>tester mosquitto :</p>
<blockquote>
<p>mosquitto_sub -t topic_iot</p>
<p>envoyer une trame mosquitto :</p>
<blockquote>
<p>mosquitto_pub -h localhost -t topic_iot -m message</p>
</blockquote>
<p>Lancer le client mqtt :</p>
<blockquote>
<p>npm install</p>
</blockquote>
<blockquote>
<p>node index.js #topic_iot detect/mouvement</p>
</blockquote>
<h2 id="Explication">Explication de la solution</h2>
<p>La solution permet d'envoyer la distance qui a été enregistré à notre serveur via une interface web qui affiche les données reçu. MQTT Mosquitto nous permet de facilité la communication entre notre objet connecté et notre serveur </p>

<h2 id=difficulté>Difficulté rencontré</h2>
<p>La Carte ESP8266 MOD n'était pas reconnu par notre Arduino. En effet en téléchargeant le driver sur MAC OS X, un problème concernant la siganture de celui-ci était présent.
<li>Télécharger le driver :
<blockquote>
<p>Se rendre dans les Préférences système -> Sérutité et confidentialité -> Authorisé le developpeur de ce logiciel </p>
</blockquote>
<blockquote>
<p>Taper la commande suivante sur votre terminal  : sudo kextutil /Library/Extensions/usbserial.kext/</p> 
</blockquote>
 </p>
</body>

</html>
