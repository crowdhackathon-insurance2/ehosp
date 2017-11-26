<?php

namespace Insurance\Http\Controllers;

use Illuminate\Http\Request;

class InsuranceController extends Controller
{
    public function index()
    {
        return view('insurance');
    }
}
