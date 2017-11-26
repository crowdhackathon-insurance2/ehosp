<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateUsersTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('users', function (Blueprint $table) {
            $amka = ['18041887678955', '140219905688646'];
            $blood_types = ['A+', 'B', '0'];
            $org_don = ['YES', 'NO'];
            
            $table->increments('id');
            $table->string('name');
            $table->string('email')->unique();
            $table->string('password');
            $table->string('amka')->default($amka[array_rand($amka)]);
            $table->string('blood_type')->default($blood_types[array_rand($blood_types)]);
            $table->string('org_don')->default($org_don[array_rand($org_don)]);
            $table->rememberToken();
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('users');
    }
}
