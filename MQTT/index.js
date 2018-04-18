const mqtt = require('mqtt');
const mysql = require('mysql');
fs = require('fs');
const client = mqtt.connect('mqtt:localhost:1883');
const mysqlConnection = mysql.createConnection({
  host: "127.0.0.1",
  user: "root",
  password: "root",
  database: 'mqttDb'
})

client.on('connect', () => {
  client.subscribe('detect/mouvement');
  console.log("connected ")
});

client.on('message', (topic, message) => {
  if(topic === 'detect/mouvement') {
    console.log(message.toString());
    post = {
      'sensor_name': 'movements sensor',
      'value': message.toString()
    };
    mysqlConnection.query("INSERT INTO `iot_datas` SET ?",post, function(error) {
      if(error) {
        console.log(error);

      } else {
        console.log(error);
      }
    })
  }
})
