@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading">
                    <h1> Dashboard </h1>
                </div>

                <div class="panel-body">
                    @if (session('status'))
                        <div class="alert alert-success">
                            {{ session('status') }}
                        </div>
                    @endif

                    <p>
                        Ανάλογα με το ρόλο του χρήστη (π.χ. νοσοκόμος, ιατρός, ασφαλιστής κλπ.)
                        θα εμφανίζεται και η αντίστοιχη σελίδα-υπηρεσία.
                    </p>

                    <a class="btn btn-primary btn-lg" href="{{ route('hospital') }}" type="button"> Hospital </a>
                    <a class="btn btn-primary btn-lg" href="{{ route('insurance') }}" type="button"> Insurance </a>
                    <a class="btn btn-primary btn-lg" href="{{ route('api') }}" type="button"> API </a>
                </div>
            </div>
        </div>
    </div>
</div>
@endsection
