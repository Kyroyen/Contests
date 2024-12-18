class CS:
    class Meta:
        flat_fields = []
    def ts(self, x):
        for ff in self.Meta.flat_fields:
            print("f",ff)
            for i in getattr(self.__class__, ff).__class__.Meta.fields:
                print(x[i])

class PS:
    class Meta:
        fields = ["a","b","r"]
				
class TM(CS):
    user = PS()
    class Meta:
        flat_fields = ["user"]


        
