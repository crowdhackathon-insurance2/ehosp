<?php

namespace Insurance\Http\Controllers;

use Illuminate\Http\Request;

class ApiController extends Controller
{
    public function index()
    {
        return view('api');
    }
}