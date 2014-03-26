#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        virtual ~Entity();

    public:

        bool IsAlive();


        virtual int get_coord_x() = 0;
        virtual int get_coord_y() = 0;
        virtual void set_coord_x(int new_x) = 0;
        virtual void set_coord_y(int new_y) = 0;
        virtual bool crash(int x_other, int y_other ,int n_coord) = 0;

        virtual int get_test() = 0;


    protected:

    int life;



};

#endif // ENTITY_H
