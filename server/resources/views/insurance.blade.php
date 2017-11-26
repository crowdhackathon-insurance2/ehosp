@extends('layouts.app')

@section('content')
<div >
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading"> 
                    <h1> Insurance </h1>
                </div>

                <div class="panel-body">
                <div class="container">  
                    </div>
                    <table class="table table-hover">
                        <thead>
                        <tr>
                            <th>Κωδικος Συμβολαίου</th>
                            <th>Ονοματεπώνυμο</th>
                            <th>User Id</th>
                            <th>Κόστος</th>
                            <th>Περιγραφή Συμβολαίου</th>
                        </tr>
                        </thead>
                        <tbody>
                        <tr>
                            <td>AC-5422</td>
                            <td>PAPADOPOULOS NIKOLAOS</td>
                            <td>1234</td>
                            <td>10000$</td>
                            <td>Πακέτο ατυχήματος: Κάλυψη ιατροφαρμακευτικών εξόδων από ατύχημα, κεφάλαιο σε περίπτωση απώλειας ζωής ή ανικανότητας και βοήθεια στην καθημερινότητα μετά από σοβαρό περιστατικό</td>
                            
                        </tr>
                        
                        </tbody>
                    </table>
                </div>
            </div>

            <div class="panel panel-default">
                <div class="panel-heading">
                    <h1> Συμβόλαια </h1>
                </div>
                <div class="panel-body">
                    <button class="btn btn-primary btn-lg" type="button"> Νέο συμβόλαιο </button>
                    <button class="btn btn-primary btn-lg" type="button"> Ανανέωση συμβολαίου </button>
                </div>
            </div>
        </div>
    </div>
</div>
@endsection
