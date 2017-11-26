<?php

namespace Insurance\Http\Controllers;

use Illuminate\Http\Request;

class HospitalController extends Controller
{
    public function index()
    {
        return view('hospital');
    }
}
