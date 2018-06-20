package com.pby.imp;

import com.pby.api.UserApi;
import com.pby.model.User;

public class UserImpl implements UserApi {
    @Override
    public User getUser(long id) {
        User user = new User();
        user.id = 0;
        user.name = "pp";
        return user;
    }
}
