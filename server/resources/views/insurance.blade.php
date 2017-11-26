@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading"> 
                    <h1> Insurance </h1>
                </div>

                <div class="panel-body">
                <div class="container">
  <h2>Hover Rows</h2>
  <p>The .table-hover class enables a hover state on table rows:</p>            
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
      </tr>
      
    </tbody>
  </table>
</div>

                </div>
            </div>
        </div>
    </div>
</div>
@endsection
