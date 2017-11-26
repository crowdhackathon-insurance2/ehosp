@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading">
                    <h1>Hospital</h1>
                </div>
                <div class="panel-body">
                    <table class="table table-striped">
                        <thead>
                            <tr>
                                <th>#</th>
                                <th>First Name</th>
                                <th>Last Name</th>
                                <th>AMKA</th>
                                <th>Blood Type</th>
                            </tr>
                        </thead>
                        <tbody>
                            <tr>
                                <th scope="row">1</th>
                                <td>NIKOLAOS</td>
                                <td>PAPADOPOULOS</td>
                                <td>123456789</td>
                                <td>A+</td>
                            </tr>
                        </tbody>
                    </table>

                    <button class="btn btn-primary btn-lg" type="button">Αίτηση ιατρικού ιστορικού</button>
                </div>
            </div>
            <div class="panel panel-default">
                <div class="panel-heading">
                    <h1> Κοστολόγηση </h1>
                </div>
                <div class="panel-body">
                    <button class="btn btn-primary btn-lg" type="button">Kοστολόγηση Ιατρικών εξόδων</button>
                    <button class="btn btn-primary btn-lg" type="button">Αποστολη Τιμολογίου</button>
                </div>
            </div>
        </div>
    </div>
</div>
@endsection
