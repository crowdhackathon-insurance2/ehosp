@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading"> 
                    <h1>Welcome</h1>
                </div>

                <div class="panel-body">
                    @if (session('status'))
                        <div class="alert alert-success">
                            {{ session('status') }}
                        </div>
                    @endif

                    <h3>
                        Πληροφοριακό σύστημα διαχείρισης και υποστήριξης 
                        έξυπνων καρτών υγείας RFID
                    </h3>
                </div>

            </div>
        </div>
    </div>
</div>
@endsection
