<?php

try {
    $bdd = new PDO('mysql:host=localhost;dbname=5MOC_IOT;charset=utf8', 'root', 'root');
} catch (PDOException $e){
    print_r("ERROR : " . $e);
    die();
}
$result = $bdd->query("SELECT * FROM iot_datas", PDO::FETCH_ASSOC);
$result->setFetchMode(PDO::FETCH_OBJ);

require_once("header.php");

?>


<main role="main" class="container with-nav">
    <?php

    if($result->rowCount() != 0) {
        ?>
        <div class="starter-template">
            <h1>Donnée</h1>
            <br/>
            <table class="table">
                <thead class="thead-light">
                <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Nom</th>
                    <th scope="col">Date</th>
                    <th scope="col">Valeur</th>
                </tr>
                </thead>
                <tbody>
                <?php

                while ($datas = $result->fetch()){
                    var_dump($datas)
                    ?>
                    <tr>
                        <th scope="row"><?php echo $datas->id;?></th>
                        <td><?php echo $datas->objet_nom;?></td>
                        <td><?php echo $datas->date;?></td>
                        <td><?php echo $datas->valeur;?></td>
                    </tr>
                <?php
                }
                ?>
                </tbody>
            </table>
        </div>
        <?php
    } else {
        ?>

    <h1 class="display-4 text-center">Aucune donnée pour le moment ..</h1>
        <?php
    }
    ?>

</main>
<script src="jquery-3.3.1.min.js"></script>

<script src="https://code.highcharts.com/highcharts.js"></script>
</body>
</html>